#include<bits/stdc++.h>
using namespace std;
string b={};
int main(){
int n;
cin>>n;
for(int i=0;i<n;i++){
    int m;
    cin>>m;
    char c;
    cin>>c;
    for(int j=0;j<m;j++){
        b+=c-97;
    }
}
int left=0,right=b.size()-1,cnt=0;
while(left<right){
    if(b[left]!=b[right])cnt++;
    left++;
    right--;
}cout<<cnt;
return 0;}
