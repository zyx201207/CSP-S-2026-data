#include<bits/stdc++.h>
using namespace std;
long long a[200010],ans;
char c[200010],b[200010];
int n,k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			b[k]=a[j];
			k++;
		}
	}
	for(int i=1;i<=k/2;i++){
		if(b[i]!=b[k-i+1]) ans++;
	}
	cout<<ans;
	return 0;
} 
//#include<bits/stdc++.h>
//using namespace std;
//long long a[200010],x[3],y[3],ans;
//char c[200010];
//int n,b,j,k,m;
//int main(){
//	//freopen("string.in","r",stdin);
//	//freopen("string.out","w",stdout);
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>a[i]>>c[i];
//		m+=a[i]%2;
//		if(c[i]==c[i-1]) a[i-1]+=a[i],i--,n--;//ºÏ²¢ 
//	}
//	j=1,k=n; 
//	x[1]=a[j],x[2]=c[j],y[1]=a[k],y[2]=c[k];
//	while(x[1]!=0&&y[1]!=0){
//		if(x[1]>y[0]){
//			if(x[2]==y[2]) ans+=x[1]-y[1];
//			a[j]-=a[k];
//			k-=1;
//		}
//		else if(x[1]==y[1]){
//			if(k-j==1) break;
//			k-=1,j+=1;
//			}
//		else{
//			if(x[2]==y[2]) ans+=y[1]-x[1];
//			a[k]-=a[j];
//			j+=1;
//		}
//		x[1]=a[j],x[2]=c[j],y[1]=a[k],y[2]=c[k];
//	}
//	cout<<ans;
//	return 0;
//} 
