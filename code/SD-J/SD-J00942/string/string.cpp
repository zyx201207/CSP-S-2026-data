#include<bits/stdc++.h>
using namespace std;
#define int long long  
const int N=2e5+5;
int n;
pair<int,char >a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	int l=1,r=n;
	int suml=a[l].first;
	char cl=a[l].second;
	int sumr=a[r].first;
	char cr=a[r].second;
	int f=0;
	int ans=0;
	while(l<r){
		//cout<<suml<<' '<<cl<<' '<<sumr<<" "<<cr<<'\n';
		f=(cl!=cr);
		ans=ans+min(suml,sumr)*f;
		if(sumr<suml){
			suml-=sumr;
			r--;
			sumr=a[r].first;
			cr=a[r].second;
		}else if(sumr>suml){
			sumr-=suml;
			l++;
			suml=a[l].first;
			cl=a[l].second;
		}else if(sumr==suml){
			l++;
			suml=a[l].first;
			cl=a[l].second;
			r--;
			sumr=a[r].first;
			cr=a[r].second;
		}
	}
	cout<<ans;
	return 0;
}//1000000000
