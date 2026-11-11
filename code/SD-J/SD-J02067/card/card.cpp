#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],ans[M];
struct node{
	bool ff=0;
	int idx;
}f[M];
int b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		int R=0;
		for(int j=i;j<=n;j++){
			if(!f[a[j]].ff){
				b[++R]=a[j];
				f[a[j]].idx=R;
				f[a[j]].ff=1;
			}else{
				if(R>=f[a[j]].idx){
					R=f[a[j]].idx;
				}
				else{
					b[++R]=a[j];
					f[a[j]].idx=R;
				}
			}
		}
		for(int j=1;j<=R;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
/*#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],ans[N];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		string s="";
		for(int j=i;j<=n;j++){
			char ch=a[j]+'0';
			int sf=s.find(ch);
			if(sf<0){
				s+=ch;
			}else{
				s.erase(sf,s.size()-sf); 
				s+=ch;
			}
		}
		
		for(int j=0;j<s.size();j++){
			ans[s[j]-'0']++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} */
