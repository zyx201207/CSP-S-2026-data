#include <bits/stdc++.h>
using namespace std;

int a[5005];
int v[5005];
bool p[3005];
int ans[3005];
int ans2[100005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m; cin>>n>>m;
	bool is=true; int lst=-1;
	int es=0;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (is){
			if (a[i]<lst){
				is=false;
			}
			else{
				if (lst==a[i]){
					ans2[es]++;
				}
				else{
					lst=a[i];
					es++;
					ans2[es]=ans2[es-1]+1;
				}	
			}
		}
	}
	
	if (is){
		for (int i=1;i<=es;i++){
			cout << ans2[i] << ' ';
		}return 0;
	}
	
	for (int i=1;i<=n;i++){
		int c=0;
		for (int j=i;j<=n;j++){
			if (!p[a[j]]){
				c++;
				p[a[j]]=true;
				v[c]=a[j];
			}
			else {
				int st;
				for (int k=1;k<=c;k++){
					if (v[k]==a[j]){
						st = k; break;
					}
				}
				for (int k=st+1;k<=c;k++){
					p[v[k]]=false; v[k]=0;
				}
				c = st;
			}
		}
		for (int j=1;j<=m;j++){
			if (p[j]) ans[j]++;
			p[j] = false;
		}
		for (int j=1;j<=c;j++){
			v[j]=0;
		}
	}
	
	for (int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}