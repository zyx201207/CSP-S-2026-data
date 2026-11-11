#include<bits/stdc++.h>
using namespace std;
long long a,b,s[500010],n[300010]={},v[300010]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>a>>b;
	for(long long i=1;i<=a;i++){
		cin>>s[i];
	}
	stack <long long> k;
	
	for(long long i=1;i<=a;i++){
		for(long long j=i;j<=a;j++){
			k.push(s[j]);
			if(v[s[j]]!=0){
				k.pop();
				while(!k.empty()&&k.top()!=s[j]){
					v[k.top()]=0;
					k.pop();
				}
			}else{
				v[s[j]]=1;
			}
		}
		while(!k.empty()){
			k.pop();
		}
		for(long long j=1;j<=b;j++){
			n[j]+=v[j];
			v[j]=0;
		}
		
	}
	for(long long i=1;i<=b;i++){
		cout<<n[i]<<" ";
	}
	return 0;
}
