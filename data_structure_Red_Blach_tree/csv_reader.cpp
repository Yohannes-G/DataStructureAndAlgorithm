#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Red_Black_Tree_prac.cpp"

using namespace std;
int csv_reader(){
     BuildRedBlack tree;//declaring a tree 
	 Node *root;  

	string ID_Name_List[500][3];
		std::ifstream file("Csv_Reader.csv");
		for (int row = 0; row <= 500; row++){
			std::string line;
			std::getline(file, line);
			if (!file.good())
				break;
			std::stringstream iss(line);

			for (int col = 0; col < 5; ++col){
				string val;
				getline(iss, val, ',');
				if (!iss.good())
					break;
				stringstream convertor(val);
				convertor>> ID_Name_List[row][col];
               // cout<<ID_Name_List[row][col]<<"\n";
			}
		}
 
    
   cout<<"WELCOME TO OUR ADVANCED RED BLACK DATA STRUCTURE"<<"\n";
   cout<<"The purpose of this code is to build red black tree "<<"\n";
   cout<<"with integer key of students ID, Name:"<<"\n";
   cout<<"1-build tree\n 2-searching\n 3-findMin and Max\n 4-Inorder tree\n 5-insert rest of items\n 6-remove 5 items\n 7-exit"<<"\n";
   for(int i=0;i<6;i++){ 
   cout<<"Enter Numbers from 1-6 to choose operations from above:  ";
   int n;
   cin>>n;
   switch(n){
      case 1:   
                for (int i=0; i<450; i++)
                    {   
                        stringstream conv(ID_Name_List[i][0]);
                        int a;
                        conv>>a;
                        tree.insert(a);
                        cout<<" "<<ID_Name_List[i][0]<< "    \t"<< ID_Name_List[i][1]<<"     \t"<< ID_Name_List[i][2] << endl;
                    }  

                tree.printLevelOrder();
                break;
      case 2:
                cout<<"Enter the ID you want to search:  ";
                int n;
                tree.search();
                break;
      case 3:
                 
                cout<<"Left most person ID: "<<tree.findMin()<<"\n";
                cout<<"Right most person ID: "<<tree.findMax()<<"\n";
                break;
      case 4:
                tree.printInOrder();
                break;
      case 5:
                cout<<"We are going to insert the rest of 50 items into the RBtree: "<<endl;
            for (int i=450; i<500; i++)
                    {   
                        stringstream conv(ID_Name_List[i][0]);
                        int a;
                        conv>>a;
                        tree.insert(a);
                       // cout<<" "<<ID_Name_List[i][0]<< "    \t"<< ID_Name_List[i][1]<<"     \t"<< ID_Name_List[i][2] << endl;
                    }  
                    for(int j=0;j<500;j++){
                          cout<<" "<<ID_Name_List[j][0]<< "    \t"<< ID_Name_List[j][1]<<"     \t"<< ID_Name_List[j][2] << endl;
                    }
                    break;
      case 6:
               for(int i=0;i<5;i++){
                cout<<"enter the next ID to delete 5 items:  ";
                cin>>n; 
                tree.deleteByVal(n);
               }
                
                tree.printLevelOrder();  
                break;

     case 7: 
           return 0;        
     } 
    
   }
}
int main(){
    csv_reader();
}