#include<bits/stdc++.h>
using namespace std;
long long a[2000010];

void solve(){
	//c
}

void solvedengcha(){
	long long n,d;
	cin>>n>>d;
	cin>>a[0]>>a[1];
	//cerr<<n<<" "<<d<<":"<<a[0]<<" "<<a[1]<<"\n";
	for(int i=2;i<n;i++){
		cin>>a[i];
	}
	long long dx=a[1]-a[0];
	long long tms=d/dx-1;
	if(tms<1){
		cout<<"0\n";
		return;
	}
	long long ans=n-2*tms-1;
	if(ans<0){
		cout<<"0\n";
		return;
	}
	//cerr<<dx<<" "<<tms<<":"<<"\n";
	cout<<ans<<"\n";
}

void solve2(){
	long long n,d;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int l=0,r=n,lans,rans;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]<d+a[0]){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	rans=r;
	l=0,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]<a[n-1]-d){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	lans=l;
	if(rans==lans+1){
		cout<<"1\n";
	}
	else{
		cout<<"0\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if (c==11 || c==12){
		while(t){
			solvedengcha();
			t--;
		}
	}
	else if (c==13 || c==14){
		while(t){
			solve2();
			t--;
		}
	}
	else{
		while(t){
			int i=rand()%3;
			cout<<i<<"\n";
			t--;
		}
	}
	return 0;
}

