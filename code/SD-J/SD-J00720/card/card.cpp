#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
int a[100000];
map<int,int> b;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		map<int,int> c;
		vector<int> d;
		for(int j=n-i+1;j<=n;j++){
			if(c[a[j]]==0){
				d.push_back(a[j]);
				c[a[j]]=1;
			}else{
				
				while(d.back()!=a[j])c[d.back()]=0,d.pop_back();
				d.pop_back();
				c[a[j]]=j;
				d.push_back(a[j]);
			}
//			for(auto l:d){
//				cout<<l<<" ";
//			}
//			cout<<endl;	
		}
		for(int j=0;j<d.size();j++){
			b[d[j]]++;
		}
//		cout<<"%%%"<<endl;
	}
//	cout<<"%%%"<<endl;
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
//Ô¤¼Æ·ÖÊý280×óÓÒ£¬fuck ccf Âà¹Ä£º1056023 

