#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,mm,ans=-1,anss,a[N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	mm=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<'\n';
//	}
//	cout<<"***************"<<'\n';
//	cout<<"m:"<<m<<'\n';
	for(int i=1;i<=n;i++){
		bool flag=1;
//		cout<<"i:"<<i<<"______________________________"<<'\n';
		ans=max(ans,anss);
		if(anss!=0){
			cout<<anss<<'\n';
			return 0;
		}
		mm=m;
		int aa=a[i];
		anss=a[i];
//		cout<<anss<<"---"<<a[i]<<'\n';
		for(int j=i+1;j<=i+mm-1;j++){
			int k=j;
			while((anss&a[k])==0){
				k++;
			}
			if(k>n){
//				cout<<111<<'\n';
				break;
			}
			while((anss&a[k])<(anss&a[k+1])){
//				cout<<(anss&a[k])<<"???"<<(anss&a[k+1])<<'\n';
				k++;
				mm++;
			}
			if(k==j){
//				cout<<anss<<"!!!"<<a[j]<<'\n';
				anss&=a[j];
//				cout<<"!!!"<<anss<<"!!!"<<'\n';
			}
			if(k!=j){
//				cout<<anss<<"&"<<"(k:"<<k<<" a[k]:"<<a[k]<<")"<<'\n';
				anss=(anss&a[k]);
//				cout<<"***"<<anss<<"***"<<'\n';
			}
			if(k!=i&&a[k]==a[j]){
				flag=0;
			}
		}
		if(anss==aa&&flag==1){
			anss=0;
		}
//		cout<<anss<<"============"<<'\n';
	}
//	cout<<ans<<'\n';
	return 0;
}
////就第三个样例没过，加强数据 
//#include<bits/stdc++.h>
//using namespace std;
//const int N=2e5+5;
//int n,m,a[N];
//bool cmp(int a,int b){
//	return a>b;
//}
//int main(){
//	freopen("and3.in","r",stdin);
//	freopen("and3.out","w",stdout);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	sort(a+1,a+n+1,cmp);
////	for(int i=1;i<=n;i++){
////		cout<<a[i]<<'\n';
////	}
////	cout<<"***************"<<'\n';
////	cout<<m<<'\n';
//	cout<<a[m]<<'\n';
//	return 0;
//}
