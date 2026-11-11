#include<iostream>
#include<deque>
using namespace std;
int n,m,a[500010],ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		deque<int> d;
		for(int j=i;j<=n;j++){
			for(int k=d.size()-1;k>=0;k--){
				if(d[k]==a[j]){
					for(int x=d.size();x>k;x--)
						d.pop_back();
					break;
				}
			}
			d.push_back(a[j]);
		}
		for(int i=0;i<d.size();i++)
			ans[d[i]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" "; 
	return 0;
}

