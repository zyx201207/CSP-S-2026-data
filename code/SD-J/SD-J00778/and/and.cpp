#include <iostream>
using namespace std;
int main(){
	freopen("and6.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long int a[n],max_=0,y;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			y=a[i] & a[j];
			if(max_<y){
				max_=y;
			}
		}
	}
	cout<<max_;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
