#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
long long b[N];
vector<int> s,s1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int x,lx;
	bool bol=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x<lx)bol=1;
		s.push_back(x);
		lx=x;
		b[x]=i;
	}
	if(bol==0){
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
		return 0;
	}
	if(n==m){
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
		return 0;
	}else{
		for(int i=1;i<=m;i++){
			b[i]=0;
		}
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	
	for(int i=0;i<n;i++){
		s1.clear();
		for(int j=i;j<n;j++){
			int y=-1;
			for(int k=0;k<s1.size();k++){
				if(s1[k]==s[j]){
					y=k;
					break;
				}
			}
			if(y==-1){
				s1.push_back(s[j]);
			}else{
				s1.erase(s1.begin()+y,s1.end());
				s1.push_back(s[j]);
			}
		}
		for(int j=0;j<s1.size();j++){
			b[s1[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
