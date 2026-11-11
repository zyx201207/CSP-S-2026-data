#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
long long a[N];
char b[N];
int main(){
	freopen("string1.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	bool k=1;
	
	for(ll i=2;i<=n;i++){
		if(b[i]==b[i-1]){
			k=1;	
		}else{
			k=0;
			break;
		}
	}
	string s="";
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	if(k){
		cout<<0;
		return 0;
	}else{
		string ac="";
		cout<<1;
		for(ll i=s.size()-1;i>=0;i--){
			ac+=s[i];
		}
		if(ac==s){
			printf("0");
			return 0;
		}else{
			string rks="";
			string acc="";
			char w[30]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
			if(s.size()%2!=0){
				cout<<1;
				rks=s.substr(0,s.size()/2);
				acc=s.substr(s.size()/2+1,s.size());
				int ans[30]={0};
				bool f=1;
				for(ll i=0;i<rks.size();i++){
					if(rks[i]=='a') ans[1]++;
					else if(rks[i]=='b') ans[2]++;
					else if(rks[i]=='c') ans[3]++;
					else if(rks[i]=='d') ans[4]++;
					else if(rks[i]=='e') ans[5]++;
					else if(rks[i]=='f') ans[6]++;
					else if(rks[i]=='g') ans[7]++;
					else if(rks[i]=='h') ans[8]++;
					else if(rks[i]=='i') ans[9]++;
					else if(rks[i]=='j') ans[10]++;
					else if(rks[i]=='k') ans[11]++;
					else if(rks[i]=='l') ans[12]++;
					else if(rks[i]=='m') ans[13]++;
					else if(rks[i]=='n') ans[14]++;
					else if(rks[i]=='o') ans[15]++;
					else if(rks[i]=='p') ans[16]++;
					else if(rks[i]=='q') ans[17]++;
					else if(rks[i]=='r') ans[18]++;
					else if(rks[i]=='s') ans[19]++;
					else if(rks[i]=='t') ans[20]++;
					else if(rks[i]=='u') ans[21]++;
					else if(rks[i]=='v') ans[22]++;
					else if(rks[i]=='w') ans[23]++;
					else if(rks[i]=='x') ans[24]++;
					else if(rks[i]=='y') ans[25]++;
					else if(rks[i]=='z') ans[26]++;
				}
				for(ll i=0;i<acc.size();i++){
					if(acc[i]=='a') ans[1]++;
					else if(acc[i]=='b') ans[2]++;
					else if(acc[i]=='c') ans[3]++;
					else if(acc[i]=='d') ans[4]++;
					else if(acc[i]=='e') ans[5]++;
					else if(acc[i]=='f') ans[6]++;
					else if(acc[i]=='g') ans[7]++;
					else if(acc[i]=='h') ans[8]++;
					else if(acc[i]=='i') ans[9]++;
					else if(acc[i]=='j') ans[10]++;
					else if(acc[i]=='k') ans[11]++;
					else if(acc[i]=='l') ans[12]++;
					else if(acc[i]=='m') ans[13]++;
					else if(acc[i]=='n') ans[14]++;
					else if(acc[i]=='o') ans[15]++;
					else if(acc[i]=='p') ans[16]++;
					else if(acc[i]=='q') ans[17]++;
					else if(acc[i]=='r') ans[18]++;
					else if(acc[i]=='s') ans[19]++;
					else if(acc[i]=='t') ans[20]++;
					else if(acc[i]=='u') ans[21]++;
					else if(acc[i]=='v') ans[22]++;
					else if(acc[i]=='w') ans[23]++;
					else if(acc[i]=='x') ans[24]++;
					else if(acc[i]=='y') ans[25]++;
					else if(acc[i]=='z') ans[26]++;
				}
				int maxn=0;
				int maxm=2;
				cout<<rks<<" "<<acc<<endl;
				for(ll i=1;i<=26;i++){
					if(ans[i]>=maxn){
						maxn=ans[i];
						maxm=i;
					}
				}
				int sum=0;
				for(ll i=0;i<rks.size();i++){
					if(rks[i]!=w[maxm-1]){
						sum++;
						rks[i]=w[maxm-1];
					}
					if(acc[i]!=w[maxm-1]){
						sum++;
						acc[i]=w[maxm-1];
					}
					if(rks==acc){
						break;
					}
				}
				printf("%lld",sum);
			}else{
				int ans[30]={0};
				for(ll i=0;i<s.size();i++){
					if(rks[i]=='a') ans[1]++;
					else if(rks[i]=='b') ans[2]++;
					else if(rks[i]=='c') ans[3]++;
					else if(rks[i]=='d') ans[4]++;
					else if(rks[i]=='e') ans[5]++;
					else if(rks[i]=='f') ans[6]++;
					else if(rks[i]=='g') ans[7]++;
					else if(rks[i]=='h') ans[8]++;
					else if(rks[i]=='i') ans[9]++;
					else if(rks[i]=='j') ans[10]++;
					else if(rks[i]=='k') ans[11]++;
					else if(rks[i]=='l') ans[12]++;
					else if(rks[i]=='m') ans[13]++;
					else if(rks[i]=='n') ans[14]++;
					else if(rks[i]=='o') ans[15]++;
					else if(rks[i]=='p') ans[16]++;
					else if(rks[i]=='q') ans[17]++;
					else if(rks[i]=='r') ans[18]++;
					else if(rks[i]=='s') ans[19]++;
					else if(rks[i]=='t') ans[20]++;
					else if(rks[i]=='u') ans[21]++;
					else if(rks[i]=='v') ans[22]++;
					else if(rks[i]=='w') ans[23]++;
					else if(rks[i]=='x') ans[24]++;
					else if(rks[i]=='y') ans[25]++;
					else if(rks[i]=='z') ans[26]++;
				}
				ll maxn=0;
				ll maxm=2;
				for(ll i=1;i<=26;i++){
					if(ans[i]>=maxn){
						maxn=ans[i];
						maxm=i;
					}
				}
				ll sum=0;
				string rks=s.substr(0,s.size()/2);
				string acc=s.substr(s.size()/2+1,s.size());
				for(ll i=0,j=s.size()-1;i<s.size()&&j>=0;i++,j--){
					if(s[i]!=w[maxm-1]){
						sum++;
						s[i]=w[maxm-1];
					}
					if(s[j]!=w[maxm-1]){
						sum++;
						s[j]=w[maxm-1];
					}
					rks=s.substr(0,s.size()/2);
					acc=s.substr(s.size()/2,s.size());
					if(rks==acc){
						break;
					}
				}
				printf("%lld",sum);
			}
		}
		
	}
	return 0;
} 
