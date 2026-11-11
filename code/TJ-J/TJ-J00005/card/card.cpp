#include <bits/stdc++.h>
using namespace std;
int a[5000000],cnt[3000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i]; 
	while(n--){
		string s="";
		for(int i=0;i<n;i++){
			int t=s.size();
			if(s.find(a[i])==s[t]) s.substr(0,s.find(a[i])-1);
			else{
				s+=a[i];
				cnt[a[i]]++;
			}
		}
	}
	for(int i=0;i<3000000;i++){
		if(cnt[i]!=0) cout << cnt[i] << " ";
	}
}
