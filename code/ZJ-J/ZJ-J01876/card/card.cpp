#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<bool>count(m,0);
		deque<int>b;
		int cnt=0;
		for(int j=i;j<=n;j++){	
			if(count[a[j]]==0){
				b.push_back(a[j]);
				count[a[j]]=1;
			}else{
				vector<int>pos;
				int i=b.size(),f=0;
				for(int x:b){
					if(i==0){
						break;
					}
					if(a[j]==x){
						f=1;
					}
					if(!f){
						pos.push_back(x);
					}
				}
				b.clear();
				for(int x:pos){
					b.push_back(x);
				}
				b.push_back(a[j]);
			}
		}
		for(int x:b){
			s[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
