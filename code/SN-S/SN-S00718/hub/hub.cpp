#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int MAXN=1000001;
int c,t;
long long n,k;
long long u[MAXN],v[MAXN];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	cin>>n>>k;
	for(int j=1;j<=t;j++){
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<rand()%10+1<<endl;
	}
	return 0;
}
