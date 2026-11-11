#include<bits/stdc++.h>
using namespace std;
int n,ans=0,temp=0,pos=0;
struct nodd{
	int a;
	char c;
}na[200005],sta[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>na[i].a>>na[i].c;
	}
	int tp=0,ed=n-1;
	while(tp>=ed){
		if(na[tp].a==na[ed].a){
			sta[pos]=na[tp];pos++;tp++;
			sta[pos]=na[ed];pos++;ed--;
		}
		else{
			if(na[tp].a<na[ed].a){
				sta[pos]=na[tp];pos++;
				sta[pos].a=na[tp].a;sta[pos].c=na[ed].c;pos++;
				na[ed].a=na[ed].a-na[tp].a;
				tp++;
			}
			if(na[tp].a>na[ed].a){
				sta[pos].a=na[ed].a;sta[pos].c=na[tp].c;;pos++;
				sta[pos]=na[ed];pos++;
				na[tp].a=na[tp].a-na[ed].a;
				ed--;
			}
		}
	}
	for(int i=0;i<=n;i+=2){
		if(sta[i].c!=sta[i+1].c)ans+=sta[i].a;
	} 
	cout<<ans;
	return 0;
}
