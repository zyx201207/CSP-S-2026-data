#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[500005];
vector<ll> b;
int use[300005];
int main(){
	freopen("card1.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(size_t i=0;i<n;i++){
		cin>>a[i];
	}
	for(size_t i=0;i<n;i++){
		b.clear();
		for(size_t j=i;j<n;j++){
			if(use[a[j]]==0) {
				b.push_back(a[j]);
				cout<<a[j]<<endl;
				use[a[j]]++;
			}
			else if(a[j]==b.back()){
				use[a[j]]--;
				continue;
			}
			else{
				while(b.back()!=a[j]&&!b.empty()){
					cout<<"pop!!"<<b.back();
					b.pop_back();
					
				}
				use[a[j]]--;
				cout<<"same"<<a[j]<<endl;
			}
		}
		cout<<endl<<b.size()<<endl;
		for(size_t j=0;j<=b.size();j++){
			cout<<b[i]<<' ';
		}
		cout<<endl<<endl;
	}
	return 0;
}
