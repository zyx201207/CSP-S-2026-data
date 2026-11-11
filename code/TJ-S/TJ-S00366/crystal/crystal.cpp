#include<bits/stdc++.h>
using namespace std;
//bool xu=1;
int n;
long long a[500010],tmp_,INF=1000000000000;
long long m,tmp,ans=0,max_;
//int num_[2000000000010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//num_[a[i+INF]]++;
	}
	/*while(xu){
		xu=0;
		for(int i=1;i<=n-1;i++){
			if(a[i]>a[i+1]){
				xu=1;
				tmp_=a[i];
				a[i]=a[i+1];
				a[i+1]=tmp_;
				//march(a[i],a[i+1]);
			}
		}
	}*/
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<"\n";
//	}
	for(int i=n;i>=1;i--){
		tmp=m;
		max_=0;
		for(int j=i;j>=1;j--){
			if(tmp>=a[i]-a[j]){
				tmp-=(a[i]-a[j]);
				max_++;
			}
			else{
				break;
			}
		}
		ans=max(ans,max_);
	}
//for(int i=2*INF;i>=0;i--){
//
//}
	cout<<ans;;
	//system("fc crystal1.ans 1 1.out");
	return 0;
}
