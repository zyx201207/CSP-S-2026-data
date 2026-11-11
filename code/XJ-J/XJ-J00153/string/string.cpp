#include<bits/stdc++.h>
using namespace std;
const int MAX_N=200010;
int n,spcnt[MAX_N];
long long spsl[MAX_N],strl=0,ans=0;
char spc[MAX_N];
int getspi(long long si){
	si++;
	if(si>spsl[n-2])return n-1;
	if(si<=spsl[0])return 0;
	int curi=n/2,lasti=n;
	while(true){
		if(spsl[curi-1]<si&&si<=spsl[curi])
			return curi;
		if(spsl[curi]>si){
			curi=min(curi-1,curi/2);
		}else {
			curi=max(curi+1,lasti/2+curi/2);
		}
		lasti=curi;
	}
}
char getic(long long si){
	return spc[getspi(si)];
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=1){
	cout<<0;
	return 0; 
	} 
	for(int i=0;i<n;i++){
		cin>>spcnt[i]>>spc[i];
		strl+=spcnt[i]; 
		spsl[i]=spcnt[i]+(i==0?0:spsl[i-1]);
	}
	for(long long i=0;i<strl/2;i++){
//		if(i%10000==0)cout<<i<<"/"<<strl/2<<endl;
		int c1sp=getspi(i),c2sp=getspi(strl-1-i);
		if(spc[c1sp]!=spc[c2sp]){
			long long ni=min(spsl[c1sp]-1,strl-1-spsl[c2sp-1]);
			ans+=ni-i;
			i=ni;
			ans++;
		}
		else{
//			cout<<"same sp:"<<c1sp<<" "<<c2sp<<endl;
			i=min(spsl[c1sp]-1,strl-1-spsl[c2sp-1]);
//			cout<<"skip:"<<spsl[c1sp]-1<<" "<<strl-1-(spsl[c2sp-1])<<endl;
//			cout<<"skip:"<<i<<endl;
		}
	}
	cout<<ans;
	return 0;
}
