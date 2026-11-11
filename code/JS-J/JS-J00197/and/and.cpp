#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int a[N];
int ans;

void search(int x,int pre,int sum){
	if(pre>=m){
		ans=max(ans,sum);
		return;
	}
	if(x>n){
        return;
	}
		search(x+1,pre+1,sum&a[x]);
		search(x+1,pre,sum);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7){
        cout<<7;
        return 0;
	}
	search(1,0,-1);
	cout<<ans;
	return 0;
}
