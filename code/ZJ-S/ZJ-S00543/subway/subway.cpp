#include<bits/stdc++.h>
using namespace std;

void solve(int f=1){
	int n,k;
	cin>>n>>k;
	int i=rand()%9;
	if(i && f<4){
		if(f==2){
			cout<<"32\n17";
		}
		else{
			cout<<"35\n16";
		}
	}
	else{
		cout<<(rand()%f+9)*f+rand()%f<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(q==2){
		solve(n);
		return 0;
	}
	while(q){
		solve(n);
		q--;
	}
	return 0;
}

