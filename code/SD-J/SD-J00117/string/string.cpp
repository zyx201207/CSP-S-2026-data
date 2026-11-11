#include<bits/stdc++.h>
using namespace std;

const int MAXN=200005;
int n;
long long a[MAXN];
string c[MAXN];
int head=1,tail;//Í·Î²Ö¸Õë 
int len;
unsigned long long ans=0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		cin>>c[i];
		cout<<" "<<i<<"\n\n";
	}
	tail=n;
	int h=head,t=tail;
/*
	while(h<t){
		//long long mina=min(a[head],a[tail]);
		while(a[h]<a[t]&&c[h]!=c[t]
						&&c[h+1]!=c[t]){
			if(a[h]+a[h+1]<=a[t]){
				a[h+1]+=a[h];
				head++;
			}
			//cout<<head<<'\n';
		}
		while(a[tail]<a[head]
		&&c[head]!=c[tail]&&c[head+1]!=c[tail]){
			if(a[tail]+a[tail-1]<=a[head]){
				a[tail-1]+=a[tail];
				tail--;
			}
			//cout<<tail<<'\n';
		}
		//cout<<head<<" "<<tail<<'\n';
		head++;
		tail--;
	}*/
	/*
	bool flag=1;
	for(int i=2;i<=n;++i){
		if(c[i]!=c[i-1]) flag=0;
	}
	if(flag){
		//ÌØÅÐ 
		cout<<0;
		return 0;
	}
	*/

	while(head<tail){
		long long mina=min(a[head],a[tail]);
		long long maxa=max(a[head],a[tail]);
		if(c[head]!=c[tail]){
			ans+=mina;
		}
		a[head]-=mina;
		a[tail]-=mina;
		if(a[head]==0) head++;
		if(a[tail]==0) tail--;
	}
	
	cout<<ans;
	
	return 0;
}
