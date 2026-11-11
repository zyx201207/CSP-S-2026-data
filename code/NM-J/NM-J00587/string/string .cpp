#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);	
long long n;
long long s,sum=0;
char d;
string q;
cin>>n;
for(long long i=0;i<n;i++){
cin>>s>>d;
for(long j=0;j<s;j++){
q+=d;
}
}
for(long long i=1;i!=q.length();i++){
	long long r=q.size()-i-1;
if(q[i]!=q[q.size()-i-1])
sum++;

else if((q[i]==q[r])||(i>r)){
	cout<<sum;
	break;
	}
	}
return 0;
}
