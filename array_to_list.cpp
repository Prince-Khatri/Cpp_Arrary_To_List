#include<iostream>
#include<iomanip>
using namespace std;

//array without any class
int k1[100];
int l=0,w=01,zero=0,nega=0;
int length(int a[]);//
void append(int a[],int pa);//
int pop(int a[]);//
int remove(int a[],int ad);//
int index(int a[],int at);//


int choice(){
    cout<<"\n\t\tWhat do You Want to do"<<endl<<"\n\t\t\t1.Length\n\t\t\t2.Index\n\t\t\t3.Append\n\t\t\t4.pop\n\t\t\t5.remove\n\t\t\t\t";
    int ch;
    cin>>ch;
    //for choice in the above function
        
    if(ch==1){//length
    int a=length(k1);
    cout<<"\nLength of array is "<<a<<endl;
    return 1;
    }
    
    else if(ch==2){//index
    int at;//element and checker
    cout<<"\n\nEnter Element to be found"<<endl;
    cin>>at;
    int tp=index(k1,at);
    if (tp<0){//Second chance
        cout<<"\nLast Chance\nEnter Element";
        cin>>at;
        if(index(k1,at)!=-1){
            index(k1,at);
        }
        else 
            return -1;//exit case in case of error input
        
    }
    cout<<endl;
    return tp;

    }

    else if(ch==3){//append
    int ad;
    cout<<"\nEnter Element to be added"<<endl;
    cin>>ad;
    if (ad>=0||ad<0){
        append(k1,ad);
        cout<<endl;
        return 1;
        }
    else
        return -1;//exit case
    }

    else if(ch==4){//pop
        int pk=pop(k1);
        cout<<endl;
        return pk;
    }


    else if(ch==5){//remove
    cout<<"\nEnter the number to Be removed";
    int cv;
    cin>>cv;
    
    int we=remove(k1,cv);
    
    cout<<endl;
    return we;
    
    }
    else{
    //three trials after wrong input
    if(w<=3)
    {
        cout<<"\ntry "<<w<<"\n:"<<endl;w++;
        choice();
        
    }
    cout<<endl;
    return -1;
    }
}

void Entry(string spd){
    cout<<"\nX-----------X-----------X-----------X-----------X-----------X-----------X-----------X-----------X-----------X"<<endl;
    cout <<"\t\tYout have entered the stimulation the Prince Khatri"<<endl;
    cout<<"\t\tThis is an stimulaion made for "<<spd<<endl;

}

void End(){
    cout <<"\n\t\t\t\tStimulation Ended"<<endl;
    cout<<"\nX-----------X-----------X-----------X-----------X-----------X-----------X-----------X-----------X-----------X"<<endl;
    
    
}


int main(){
    try{
    for (int i=0;i<100;i++){
        k1[i]=0;
    }
    Entry("Array TO List");
    string cp;
    cout<<"\n\t\tEnter no. of Initial elements:";
    cin>>l;
    if(cin.fail()){
        throw 1;
    }
    
    if(l>0)
        cout<<"\n\t\t\tEnter elements: ";
    
    for(int i=0;i<l;i++){
        cin>>k1[i];
        if(cin.fail()){
            throw 1;//for ... catch
        }
        
    }
    
    
    do{
        int pkl=choice();
        if(pkl==-1){
            throw 1;
        }
        cout<<"\nDo you want to work more(y/n)"<<endl;

        
        cin>>cp;
        
        if (cp[0]=='y'||cp[0]=='Y'){
            continue;
        }
        else{
            throw cp;
        }



    }while(cp[0]=='y'||cp[0]=='Y');
    }
    catch(const string * msg){
        cout<<endl;
        for(int i=0;i<60;i++){
            cout<<"_";}
        cout<<endl<<"|";
        cout<<setw(50)<<"Error! Wrong Input undefined Input "<<"|"<<msg<<"|";
        cout<<endl;
        for(int i=0;i<60;i++){
            cout<<"¯";
            }
    }
    catch(...){
        cout<<endl<<" ";
        for(int i=0;i<38;i++){
            cout<<"_";}
        cout<<endl<<"|";
        cout<<setw(38)<<"Unexpected Error!!! Wrong Input"<<"|";
        cout<<endl<<" ";
        for(int i=0;i<38;i++){
            cout<<"¯";
            }
        
    }




    End();    

    
}

int length(int temp[]){
    int i;
    int kp=zero;
    for ( i=0;i<100;i++){
        
        if (temp[i]==0){
            if (kp==0){//end of array
                break;
            }
            else{
                kp--;//check false end
            }
        }
    }
    return i;
}

void append(int temp[],int at){
    if (at==0){
        zero++;
    }
    temp[l]=at;
    l++;

}

int pop(int temp[]){
    int te=temp[l];//storing in temp variable
    temp[l]=0;//changing value to zero
    l--;
    
    return 1;//error handling
}

int index(int temp[],int at){
    int flag=0,i;
    for (i=0;i<l;i++){
        if (temp[i]==at){//index found
            flag=1;
            break;
        }
    }
    //checking index found case
    if (flag==0){
        cout<<"\nElement not found";
        return -1;
    }
    else{
        cout<<"\nElement found at "<<i<<endl;
        return i;
    }
}

int remove(int temp[],int at){
    int kp=index(temp,at);
    // checking valid input
    if(kp>=0){
        int kl=temp[kp];
        temp[kp]=0;//removing
        //reassembling the elements
        for (int i=kp;i<l;i++){
            temp[i]=temp[i+1];
        }
        l--;//decreasing the length
        return kl;
    }
    //in case of false input

    else{
        if(w<=3){
            cout<<"\nEnter valid Element"<<endl<<"\nTrial left "<<3-w<<endl;
            
            int po;
            cin>>po;
            w++;
            return remove(temp,po);
    }
    else{
        return -1;//for wrong case
    }}
}



//issue 1
