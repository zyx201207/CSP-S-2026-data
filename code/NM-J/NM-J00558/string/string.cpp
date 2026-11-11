#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char c[N];
pair<long long,long long> s[N];
long long l,sf,sc,ef,ec,cnt;
bool sti=false,stj=false;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	s[1].first=0;
	s[1].second=s[1].first+a[1];
	for(int i=2;i<=n;i++){
		s[i].first=s[i-1].second;
		s[i].second=s[i].first+a[i];
	}
	int i=1,j=1;
	while(i<(n/2+1)&&(j+n-1)>=(n/2+1)){
		sf=s[i].first+l-1-1;
		sc=s[i].second-1+l-1-1;
		if(sti)sc=sc-(ec-ef);
		sti=true;
		ef=s[j+n-1].first;
		ec=s[j+n-1].second-1;
		if(stj)ec=ec-(ec-sc);
		stj=true;
		if(sf>ef){
			if(c[i]!=c[i+n-1]){
				cnt+=ec-sf+1;
			}
			i++;
			sti=false;
		}else if(sf<ef){
			if(c[i]!=c[i+n-1]){
				cnt+=ec-ef+1;
			}
			j--;
			stj=false;
		}else{
			if(c[i]!=c[i+n-1]){
				cnt+=ec-ef+1;
			}
			i++;
			j++;
			sti=false,stj=false;
		}
	}
	cout<<cnt;
	return 0;
} 
