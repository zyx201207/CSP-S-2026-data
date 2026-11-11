#include<bits/stdc++.h>//老天保佑！ 
using namespace std;
int n,a[500005],ans,sum=1,lh,cnt,ccnt;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			lh+=1;
		}else{
			if(sum<lh){
				cnt=a[i-1];
				ccnt=i-1;
			} 
			sum=max(sum,lh);
			lh=1;
		}
	}
	if(sum==1){
		if(n%2){
			cnt=a[n/2+1];
			ccnt=n/2+1;
		}else{
			cnt=a[n/2];
			ccnt=n/2;
		}
	}
	for(int i=1;i<=ccnt;i++){
		a[i]=abs(a[i]-cnt);
	}
	sort(a+1,a+ccnt+1);
	for(int i=1;i<=ccnt;i++){
		if(a[i]<=m){
			ans+=1;
			m-=a[i];
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
/*wwwwwwwwwwwwwwwwwwww
w
w
w
w
w
wwwwwwwwwwwwwwwwwwww           w                                                                                            嚎到我了，老嚎子 
w
w
w
w
w
w
w
w*/
