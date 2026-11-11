#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long tong[500005];
long long cnt[500005];
string s;
void f(long long you,long long number){
	for(long long i=you;i>=0;i--){
		s[i]='*';
		if((s[i-1]-'0')==number){
			return;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s="";
		for(int j=1;j<=n;j++){
			tong[a[j]]++;
			s+=tong[a[j]];
			if(tong[a[j]]>i){
				tong[a[j]]--;
				f(j-1,tong[a[j]]);
			}
		}
		for(int j=0;j<=s.size();j++){
			if(s[j]!='*'){
				cnt[s[j]-'0']++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[a[i]]!=114514){
			cout<<cnt[a[i]]<<" ";
		}
		cnt[a[i]]=114514;
	}
	return 0;
}
