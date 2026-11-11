#include <bits/stdc++.h>
using namespace std;
int arr[500001],s[300001],arr2[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		//cout<<arr[i]<<' ';
	}
	
	int r=1;
	for(int i=1;i<=n;i++){
		r=i-1;
		for(int j=i;j<=n;j++){
			for(int h=i;h<=r;h++){
				if(arr2[h]==arr[j]){
					r=h-1;
					break;
				}
			}
			r++;
			arr2[r]=arr[j];
		
			//cout<<r<<' ';
		}
		//cout<<endl;
		for(int j=i;j<=r;j++){
		//	cout<<arr2[j]<<' ';
			s[arr2[j]]++;
		}
		//cout<<endl;
		for(int j=i;j<=n;j++){
		arr2[j]=0;
	}
	
	}
	for(int i=1;i<=m;i++){
		printf("%d ",s[i]);
	//	cout<<s[i]<<' ';
	}
	return 0;
} 
