include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,s[200005],sum=0,l,r;
char s2[200005];
cin>>n;
for(int i=0;i<n;i++){
cin>>s[i]>>s2[i];
}
l=0,r=n-1;
while(l<r){
if(s2[l]!=s2[r]){
sum+=min(s[l],s[r]);
}
s[l]-=min(s[l],s[r]),s[r]-=min(s[l],s[r]);
if(s[l]==0) l++;
if(s[r]==0) r--;
}
cout<<sum;
fclose(stdin);
fclose(stdout);
return 0;
}
