#include<bits/stdc++.h>
//asd
using namespace std;
struct node{
	int a;char c;
}ac[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;long long s=0;cin>>n;
	for(int i=0;i<n;i++){
		int asd;char basd;
		cin>>asd>>basd;
		s+=asd*1ll;
		ac[i]={asd,basd}; 
	}
	s=s/2;
	int l=0,r=n-1;long long sum=0,pop=0;
	while(1){
		if(pop>=s*1ll){
			break;
		}
		if(ac[l].a>ac[r].a){
			pop+=1ll*ac[r].a;
			ac[l].a-=ac[r].a;
			if(ac[r].c!=ac[l].c){
				sum+=1ll*ac[r].a;
			}
			--r;
		}
		else{
			pop+=1ll*ac[l].a;
			ac[r].a-=ac[l].a;
			if(ac[r].c!=ac[l].c){
				sum+=1ll*ac[l].a;
			}
			++l;
		}  
	}
	cout<<sum;
	//tj-j00401
	//
	return 0;
} 

