#include "brent.h"
using namespace std;

Brent::Brent(int table_size){

    entry a;
    for(int i=0; i<table_size; i++){
        data_vec.push_back(a);
    }
}
 int Brent::hash(int key)  { 
        return key % data_vec.size();
}
int Brent::hash2(int key) { 
        return int(key/data_vec.size())%data_vec.size();
    }
vector<int> Brent::calculateLQ(int index, int step) { 
        vector<int> temp;
        temp.push_back(index);
        do {
            // Collision: Linear quotient
            index = (index + step)%data_vec.size();
            temp.push_back(index);
        }while(data_vec[index].valid == true);
        //temp.push_back((index + step)%data_vec.size());
        return temp;
}

void Brent::insert(int key){   
int index= hash(key);
int step = hash2(key) == 0 ?  1 :  hash2(key);
if(data_vec[index].valid == false){
    data_vec[index].data = key;
     data_vec[index].valid = true;
}
else if(data_vec[index].valid == true){
    
      vector<int> table = calculateLQ(index,step);
      int S = table.size(); 
 
      //if(S == data_vec.size()) return;

     int smallest_sum = data_vec.size();
     int pos_best = -1, pos_rep = -1;
      

      for(int i=1; i<S; i++){
        int pos_ind = table[i-1];
        
            int new_step = hash2(data_vec[pos_ind].data) == 0 ?  1 :  hash2(data_vec[pos_ind].data); // kontrol et 
            vector<int> table_j = calculateLQ(pos_ind, new_step); // stepi değiştirmeyi unutma
         
            for (int j = 1; j < table_j.size(); j++) {
             int cur = table_j[j];
            
            if (data_vec[cur].valid == false && (i+j)< smallest_sum) {
              smallest_sum = i+j;
              pos_best=cur;
              pos_rep = table[i-1];
            }

        }
}

if(pos_best != -1 && smallest_sum<S){
data_vec[pos_best].data = data_vec[pos_rep].data;  
data_vec[pos_best].valid = true; 
                
data_vec[pos_rep].data = key; 
data_vec[pos_rep].valid = true;

}

else {
    
    int last_pos = table.back(); 
   data_vec[last_pos].data = key;
    data_vec[last_pos].valid = true;
}



}

}

int Brent::find_num_probes(int key) const{

int index = key % data_vec.size();
int probes = 1;

    if (data_vec[index].data == key) {
        return probes;
    }

    int step = key / data_vec.size();
     if(step == 0) step = 1;
    
    do {
        probes++;
        index = (index + step) % data_vec.size();
    } while (data_vec[index].data != key);

    return probes;
} 




double Brent::find_average_num_probes() const{
 
double count=0,sum=0;
    for(entry key:data_vec){
        if(key.valid == true){       
            sum+= find_num_probes(key.data);
            count++;    
        }
    }
    return sum/count;

}

