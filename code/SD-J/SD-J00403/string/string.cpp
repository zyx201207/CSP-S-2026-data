#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int n;
long long m,sum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	long long m1=0,m2=m-1;
	int i=0,j=n-1;
	//int u=0;//
	//cout<<n<<' '<<m<<endl;//
	while(m1<=m2){
		//cout<<a[i]<<' '<<a[j]<<' '<<c[i]<<' '<<c[j]<<' ';//
		//cout<<i<<' '<<j<<' '<<m1<<' '<<m2<<endl;//
		if(a[i]==a[j]){
			if(c[i]!=c[j]){
				sum+=a[i];
				//u++;//
				//cout<<c[i]<<' '<<c[j]<<endl;//
				//cout<<a[i]<<' '<<sum<<' '<<u<<' '<<1<<endl;//
			}
			m1+=a[i];
			m2-=a[i];
			i++;
			j--;
		}else if(a[i]>a[j]){
			m1+=a[j];
			m2-=a[j];
			a[i]-=a[j];
			if(c[i]!=c[j])
				sum+=a[j];
			//u++;//
			//cout<<a[j]<<' '<<sum<<' '<<u<<' '<<2<<endl;//
			a[j]=0;
			j--;
		}else{
			m1+=a[i];
			m2-=a[i];
			a[j]-=a[i];
			if(c[i]!=c[j])
				sum+=a[i];
			//u++;//
			//cout<<a[i]<<' '<<sum<<' '<<u<<' '<<3<<endl;//
			a[i]=0;
			i++;
		}
	}
	cout<<sum;
	return 0;
}
