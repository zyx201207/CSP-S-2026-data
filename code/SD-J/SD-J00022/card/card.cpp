#include<bits/stdc++.h>
#define ll long long
#define pr priority_queue
#define F first
#define endl "\n"
#define S second
#define pi pair
#define mk make_pair
#define ull unsigned long long
using namespace std;
const int N=5e5+100;
int a[N],cr[N],ans[N];
unordered_map<int,int> mp;
int n,m;
void solve(){
	int p1=0,p2=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			p1++;
		}else{
			p2++;
		}
	}
	if(a[n]==1){
		cout<<n<<' '<<p2<<endl;
	}
	else{
		cout<<p1<<' '<<n<<endl; 
	}
	return;
}
int main(){
//	system("fc card.out card4.ans");
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1||a[i]==2){
			k++;
		}
	}
	if(k==n&&n>5000){
		solve();
		return 0;
	}
	for(int i=1;i<=n;i++){ 
	    mp.clear();
		for(int j=i;j<=n;j++){
			if(!mp[a[j]]){
				mp[a[j]]=j;
			}
			else{
				int o=mp[a[j]];
				cr[o]++;
				for(int l=o;l<j;l++){
					mp[a[l]]=0;
				}
//                cr[mp[a[j]]]++;
				cr[j]--;
				mp[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			cr[j]=cr[j-1]+cr[j];
			cr[j-1]=0;
			if(cr[j]){
				continue;
			}else{
				ans[a[j]]++;
			}
		}
		cr[n]=0;
	}
	for(int i=1;i<m;i++){
		cout<<ans[i]<<' ';
	}cout<<ans[m];
	return 0;
}

