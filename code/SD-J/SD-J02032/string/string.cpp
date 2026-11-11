#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct s{
	int chang;
	char zf;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].chang>>a[i].zf;
	}
	long long l=1,r=n,lleft=0,rleft=0;
	long long sum=0;
	while(1){
		int x=min(a[l].chang,a[r].chang);
		if(a[l].zf!=a[r].zf) sum+=x;
		lleft=a[l].chang-x;
		rleft=a[r].chang-x;
		a[l].chang=lleft; 
		a[r].chang=rleft;
		if(lleft==0) l++;
		if(rleft==0) r--;
		if(l>=r) break;
	}
	cout<<sum;
	return 0;
} 
