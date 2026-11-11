#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define ft first
#define sd second
using namespace std;
long long k[200010];
char c[200010];
int n;
long long sum,ban,sum1,sum2;
vector<int> shu1,ch1,shu2,ch2;
int wei1=0,wei2;
long long sheng1,sheng2;
char zi1,zi2;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i]>>c[i];
		sum+=k[i];
	}
	ban=sum/2;
	for(int i=1;sum1+k[i]<=ban;i++){
		wei1=i;
		sum1+=k[i];
		shu1.pb(k[i]);
		ch1.pb(c[i]);
	}
	for(int i=n;sum2+k[i]<=ban;i--){
		wei2=i;
		sum2+=k[i];
		shu2.pb(k[i]);
		ch2.pb(c[i]);
	}
	wei2=n+1;
	while(!shu1.empty()&&!shu2.empty()){
		if(sheng1==0){
			sheng1+=shu1.back();
			zi1=ch1.back();
			shu1.pob();
			ch1.pob();
		}
		if(sheng2==0){
			sheng2+=shu2.back();
			zi2=ch2.back();
			shu2.pob();
			ch2.pob();
		}
		if(sheng1>=sheng2){
			if(zi1!=zi2){
				ans+=sheng2;
			}
			sheng1-=sheng2;
			sheng2=0;
		}
		if(sheng1<sheng2){
			if(zi1!=zi2){
				ans+=sheng1;
			}
			sheng2-=sheng1;
			sheng1=0;
		}
	}
	if(wei2-wei1>=2){
		char ch=c[wei1+1];
		if(sheng1!=0||!shu1.empty()){
			if(zi1!=ch){
				ans+=sheng1;
			}
			while(!shu1.empty()){
				if(ch1.back()!=ch){
					ans+=shu1.back();
				}
				shu1.pob();
				ch1.pob();
			}
		}
		if(sheng2!=0||!shu2.empty()){
			if(zi2!=ch){
				ans+=sheng2;
			}
			while(!shu2.empty()){
				if(ch2.back()!=ch){
					ans+=shu2.back();
				}
				shu2.pob();
				ch2.pob();
			}
		}
	}
	cout<<ans;
	return 0;
}
