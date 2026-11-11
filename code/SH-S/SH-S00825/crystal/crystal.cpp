#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],qzh[500005];
bool Xmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		//a[i]=i;
	}
	//m=n*(n/2);
	sort(a+0,a+n,Xmp);
	for(int i=0;i<n;i++){
		qzh[i+1]=a[i]+qzh[i];
	}
	//cout<<a[0]<<a[1]<<a[2]<<qzh[3];
	int mxn=0;
	for(int i=0;i<n-mxn;i++){
		int use=0,cnt=1;
		if(a[i]*mxn-qzh[i+mxn]+qzh[i+1]>m){
			//cout<<i<<endl;
			continue;
		}//else{
		//	cout<<"t:"<<qzh[i+mxn]-qzh[i+1]-a[i]*mxn<<" "<<m<<endl;
		//}
		for(int j=i+1;j<n;j++){
			use+=a[i]-a[j];
			if(use>m){
				break;
			}
			cnt++;
		}
		mxn=max(mxn,cnt);
	}
	cout<<mxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
