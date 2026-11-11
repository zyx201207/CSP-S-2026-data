#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long s[500010];
long long ma,cnt,da;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s,s+n);
	cnt=1;
	int i=2,l=1;
	while(i<=n){
//		cout<<"\n"<<i<<" "<<l<<" "<<m<<"\n";
		if(m<(i-l)*(s[i]-s[i-l])){
			while(l<i&&m<(i-l)*(s[i]-s[i-1])){
				cnt--;
				m+=s[i-1]-s[l];
				l++;
//				cout<<"\n"<<i<<" "<<l<<" "<<m<<" "<<(i-l)*(s[i]-s[i-1])<<"\n";
			}
		}
//		cout<<"\n";
		if(m>=(i-l)*(s[i]-s[i-1])){
			cnt++;
			da=max(da,cnt);
			m-=(i-l)*(s[i]-s[i-1]);	
		}
		i++;
	}
	cout<<da;
	return 0;
}
/*
4 4
1 5 7 6 
*/
