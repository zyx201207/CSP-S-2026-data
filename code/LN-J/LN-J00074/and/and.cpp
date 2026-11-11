#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
int m,n,num[200010]={},ii=0,ans2[200010]={};
cin>>m>>n;
for(int i=0;i<m;i++){
    cin>>num[i];
}
sort(num,num+m);
if(n==1){
    cout<<num[m-1];
    return 0;
}else{
for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
        ans2[ii]=num[i]&num[j];
        ii++;
    }
}
sort(ans2,ans2+ii);
cout<<ans2[ii-1];
fclose(stdin);
fclose(stdout);
}
return 0;



}
