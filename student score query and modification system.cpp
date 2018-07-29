#include<iostream>
#include<fstream> 
#include<string>
#include<string.h> 
#include<cstdlib>//atoi atof 
using namespace std;
struct Student{
	unsigned int id;   
	char name[10];    
	float score;
	Student* next;     
};           //define a struct, this will be used as a single node of a list 
int main(){
	ifstream is;
	is.open("c:\\users\\df\\desktop\\My C++ Code\\transcript.txt"); 
	if(!is.is_open()){                  
	cerr<<"failed to open the original transcript file£¡\n";     
	return -1;                          
    }                                    
    ofstream os; 
	 
	Student *head=NULL, *tail=NULL, *p=NULL, *q=NULL, *pp=NULL;  
    int count=0;  
	while(!is.eof()){
		p=new Student;
	    is>>p->id>>p->name>>p->score;
		p->next=NULL; 
		if(tail==NULL){
			tail=p; head=p;
		}else{
			tail->next=p; tail=p;
		}//The list has been created, for now the head is pointing at its first node,p and tail are all pointing at its last node 
	    count++;//use count to indicate how many records have been input from the txt file, which also equals the number of nodes in the list
	} 	 
    is.close();//close the file. Now we have nothing to do with the file and start to concentrate on the list in C++ 
	p=head;		
////////////////in order to check whether the list has been created successfully, we can output the list to see
    cout<<"a list has been generated according to the transcript file\nAs the list has shown, there're "<<count<<" records\nThe complete transcript looks like this: \n\n"; 
	while(p->next!=NULL){
        cout<<p->id<<' '<<p->name<<' '<<p->score<<endl;
	    p=p->next; 
	} 
	cout<<p->id<<' '<<p->name<<' '<<p->score<<endl;
////////////////this checking is not necessary if the list is really too long
    p=head;//relocate the pointer p to the first node
    cout<<endl;
    
    
    
    //From here, we start to dive into the menu:
    string ID;
    int z,x,m,n,l,y,k,j,sco=1;
	do{
	    z=x=n=m=l=-1;
	    cout<<"\nThe current menu is(choose the number on the left):\n0 add a new record after the original records\n1 search by ID\n2 end operation and quit the program\n\n";
	    cin>>n;
	    
	    
	    
	    
		if(n==0){//these are codes that enable you to add a new record after the original records  
		    int d;
			do{
				d=0;
				p=new Student;
                cout<<"\nplease input the new record you want to add£º\n\n";
	       	    cin>>p->id>>p->name>>p->score;p->next=NULL; //input a new record from keyboard and create a new node on the list
	       	    pp=head;      //pointer p is now pointing at a potential node outside of the list and is waiting to be tested. If it passes the test, it will be then formally accepted as a new node of the list
	       	    while(pp->next!=NULL){
				    if(p->id==pp->id||p->id==tail->id){//once we find the ID of the new record is the same as one of the existing record in the original list, the following operation will then be activated. 
					    delete p; cout<<"\nThe ID you want to add is already existed.\n";
						d=10; break; 
				    }					    
					pp=pp->next;
				} 
		    }while(d==10); 
		    if(tail==NULL){
			    tail=p; head=p;	    
		    }else{
			    tail->next=p; tail=p;
		    }//put the new record in the new node and link this new node to the existing list
		    count++;//so far, the new record has been added
		    p=head;//relocate the pointer p to the first node 
		    cout<<"\nthe current menu is(choose the number on the left side):\n0 back to the upper level of menu\n1 end operation and quit the program\n\n";
		    cin>>m;
		        if(m==0){z=100;}
				else if(m==1){      
					break;
				}
				

	    }else if(n==1){
		        //here are the codes enable you to search by ID
	    	p=head; //relocate the pointer p to the first node
            cout<<"\nStart to search, please input the target ID£º \n\n"; 
            cin>>ID;   
            sco=atoi(ID.c_str());
            while(p->next!=NULL){
       	        if(sco==p->id){
      	       	    cout<<"ID found£º \n";
     	       		cout<<p->id<<' '<<p->name<<' '<<p->score<<endl;
     	       		break;
          		}else{p=p->next;} 
     		}
     		if(tail->id==sco){cout<<tail->id<<' '<<tail->name<<' '<<tail->score<<endl;}
        	if((p->next==NULL)&&(p->id!=sco)) cout<<"The matched record found!£¨you can't choose the three functions in the middle of the following menu at this moment£©\n\n"; 
				//the pointer o is now pointing at the target node. If no match is found,then p points at the tail node
        	do{
        		x=y=k=j=l-1; 
				cout<<"\nthe current menu is(choose the number on the left,note: this menu is useable only after \"search\"):\n0 go back to the upper level of menu\n1 add a new record behind this record\n";
				cout<<"2 delete this record\n3 change this record\n4 end the operation and quit the program\n\n";
				cin>>l;
				
            	if(l==0){z=100;p=head;} 
				else if(l==1){//add a new record after this one
				    int h;
					do{
						h=0;
					    q=new Student;
	                    cout<<"\nplease input the new record you want to add£º\n\n";
	        	        cin>>q->id>>q->name>>q->score;q->next=NULL; //input a new record and generate a new node accordingly
	        	        pp=head;      //note:the p pointer is now pointing at the targer node which has been searched previously,and pointer q is pointing at a potential
	        	        while(pp->next!=NULL){// node outside of the list waiting to be checked.Once passed the check, the new node will be accepted into the list
					        if(q->id==pp->id||q->id==tail->id){//once find the ID of the new record is the same as one of the existed, activate following operation 
						        delete q; cout<<"\nThe ID you want to add is already existed.\n";
							    h=10; break;
						    }
					        pp=pp->next;
					    }
			        }while(h==10); 
					q->next=p->next; p->next=q; count++;//count the number of the list instantly,this is important in such a complicated program
        		    if(q->next==NULL){
        		    	tail=q;
					}  p=head;q=head;pp=head;//pointer p and q must be relocated immediately once they finish serving their duty 
					cout<<"\nthe current menu is(choose the number on the left)£º\n0 go back to the upper level of the menu\n1 end operation and quit program\n\n";
		            cin>>y;
		            if(y==0){x=200;}
				    else if(y==1){      
					    break;
				    }
				}else if(l==2){//here are codes enable you to delete this record 
					q=head;
					if(q->id==p->id){                                    
						q=head->next; head=head->next; delete p; p=head; count--;						
					}else{
					    do{
			                if(q->next->id==p->id){
						        q->next=p->next;//if pointer p is now pointing at the tail node,then p->next for this moment is NULL already.
						        delete p; p=head;//the node previously pointed by p has been deleted and released.now we relocate p to the head node
						        count--; break;
					        }else{q=q->next;} 
					    }while(q->next!=NULL);
			        }
			        cout<<"\nthe current menu is(choose numbers on the left)£º\n0 go back to the upper level of the menu\n1 end operation and quit the program\n\n";
		            cin>>k;
		            if(k==0){x=200;}
				    else if(k==1){
					    break;
				    }
				}else if(l==3){
					cout<<"please input the revised record\n\n";
					cin>>p->id>>p->name>>p->score; p=head; 
					cout<<"\nthe current menu is(choose numbers on the left)£º\n0 go back to the upper level of the menu\n1 end operation and quit the program\n\n";
		            cin>>j;
		            if(j==0){x=200;}
				    else if(j==1){      
					    break;
				    }
				}else if(l==4){ 
					break;
				}
	        }while(x==200); 
		
		}else if(n==2){ 
			break;
		}
		
    }while(z==100);



    //the menu part has been finished. below are some of the last steps including \"save\", \"output\", \"delete\" the list so as to release the space 
    cout<<"\nyou've chosen to end operation. now the modified file is shown as below: \n";
    p=head;
    while(p->next!=NULL){
    	cout<<p->id<<' '<<p->name<<' '<<p->score<<endl;
    	p=p->next;
	}
	cout<<p->id<<' '<<p->name<<' '<<p->score<<endl<<endl; 
	cout<<"There are "<<count<<" records in the txt file now\n";
	cout<<"Saving the final modified version to the original file\n"; 
	p=head; 
	ofstream("c:\\users\\df\\desktop\\My C++ Code\\transcript.txt").close();
	os.open("c:\\users\\df\\desktop\\My C++ Code\\transcript.txt",ios::app|ios::out);
	while(p->next!=NULL){
		os<<p->id<<' '<<p->name<<' '<<p->score<<endl;
		p=p->next;
	}
	os<<p->id<<' '<<p->name<<' '<<p->score;
	os.close(); 
	p=head; 
	cout<<"information saved. now start to delete the list...\n";
	while(head->next!=NULL){
	p=head;
	head=head->next;
	delete p;
    }
	delete head;
	cout<<"the list has been deleted! now quit the program\n";
return 0;	
}





