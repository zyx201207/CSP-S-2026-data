  #include<bit/stdc++.h>
 using namespace std;
 string op;
 int cnt;
 int main(){
cin>>op;
for(int i=1;i<=op.size();i++){
    for(int j=1;j<=((op.size())/2.0);j++){
        if(op[i+j]==op[op.size()-j])break;
        else {op[i+j]==op[op.size()-j];cnt++;break;}
    }
}cout<<cnt;
 return 0;
 }

