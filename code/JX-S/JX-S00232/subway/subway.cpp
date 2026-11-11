#include<bits/stdc++.h>
using namespace std;
struct sub{
	int time1;
	int time2;
};
sub a[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int sum1=0,sum2=0;
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i].time1;
		sum1+=a[i].time1;
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=q;i++){
		int k=d*(y-x);
		k+=a[i].time2;
	}
	for(int i=1;i<=n;i++){
		sum2+=a[i].time2;
	}
	cout<<sum1+sum2;
	return 0;
}/*#include<bits/stdc++.h>
using nsmespace std;
struct sub{
	int timew;
	int timehc;
};
sub a[100005];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	int sum=0,sum1=0,sum2=0;
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int ans=0;
	for(int i=1;i<=m;i++){
		cin>>a[i].timew;
		sum1+=a[i].timew;
	}
	for(int i=1;i<=q;i++){
		a[i].timehc=n*;
		sum2+=a[i].timehc;
	}
	sun=sum1+sum2;
	cout<<sum;
	return 0;
}
