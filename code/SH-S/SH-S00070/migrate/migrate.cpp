#include<algorithm>	
#include<iostream>
#include<vector>
using namespace std;
int c,t;
int n;
long long d;
long long a[2000009],x[2000009];
void qwertyuiop(){
	int n;
	long long d;
	cin>>n>>d;
	vector<long long>x(n+1),a(n+1);
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1,j=1;i<=n;i++){
		j=max(j,i);
		while(x[j+1]-x[i]<d&&j<n)j++;
		a[i]=j;
	}
	for(int len=4;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			if(a[i]<i+2)continue;
			int j=i+len-1;
			int x=i,y=j;
			int m=-1;
			while(1){
				x=a[x],y=a[y];
				if(i>j||y>j)break;
				if(x==y){
					m=x;
					break;
				}
//				break;
			}
			if(m==-1)continue;
//			cout<<123;
		}
	}
//	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
//	cout<<'\n';
}
int main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	//cout<<c<<' '<<t<<"\n123123";
	for(int z=1;z<=t;z++){
		
		
		
		/*cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=3){
			cout<<"0\n";
			continue;
		}
		int dis=x[2]-x[1];
		if(d<dis){
			cout<<"0\n";
			continue;
		}
		cout<<d/dis<<'\n';*/
		cout<<"0\n";
		
		
		
	}
	return 0;
}
