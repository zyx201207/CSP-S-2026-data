#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long x;
vector<long long> a;
long long sum[500001]={0};
struct T{
	long long sum=0;long long pos=0;long long pos1=0;
}t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> x;
		a.push_back(x);
	}
	for (int k=1;k<=n;k++){
		bool vis[500001]={true};
		for (int i=k;i<=n;i++){
		    if (t[a[i]].sum<1){
		    	t[a[i]].sum++;
		    	t[a[i]].pos=i;
			}else{
				for (int n=t[i].pos;n<=i;n++){
					vis[a[n]]=false;
					if (t[a[n]].sum>=1){
		    	        t[a[n]].sum=0;
		    	        t[a[n]].pos=0;
			        }   
				}
			}
		}
		for (int i=k;i<=n;i++){
			if (!vis[i]){
				a[i]=0;
				continue;
			}
			sum[a[i]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout << sum[i] << " ";
	}
	return 0;
} 
