#include <ios/stdc++.h>
using namespace std;
int main(){
    int R,X;
    string A,B;
    cin>>R>>A>>B>>X;
    if(R==X){ 
        cout<<"1";
    }
    else  cout<<"0";
    if(A==B&&R==X){
        cout<<"1"
    }
    else  cout<<"0";
    
    if(A-d<=2&&R==X){
        cout<<"1";
    }
    else  cout<<"0";
    if(R==X&&A==B&&A-B==0){
    cout<<"1";
    }
    else  cout<<"0"; 
    
    return 0;
}
