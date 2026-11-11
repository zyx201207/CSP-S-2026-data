#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	int mid=ceil(1.0*n/2);
	int start=mid-1;
	int left=start-1,right=start+1;
	int e[n+1];
	for(int i=1;i<=n;i++) cin>>e[i];
	sort(e+1,e+n+1);
	int a[n+1];
	a[0]=0;
	a[n]=0;
	for(int i=n;i>mid;i--) a[i-1]=e[i]-e[mid];
	for(int i=mid-1;i>=1;i--) a[i]=e[mid]-e[i];
	//cout<<a[start]<<endl<<m<<endl;
	if(a[start]>m){
		cout<<"1";
		return 0;
	}
	int res=2,sum=a[start],add=0;
	//cout<<a[left-1]<<" "<<a[right+1]<<" ";
	//for(int i=0;i<=n;i++) cout<<a[i]<<" ";
	while(1){
		if ((a[left]<=a[right]) && left!=0){
			add=a[left];
			//cout<<add;
			left-=1;
		}if( (a[left]>a[right]) && right!=n){
			add=a[right];
			//cout<<add;
			right+=1;
		}
		if(sum+add<=m){
			sum+=add;
			res+=1;
		}else break;
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
