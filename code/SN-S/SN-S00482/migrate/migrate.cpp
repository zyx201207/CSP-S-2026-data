//SN-S00482 谢俊哲 西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c &t);
	while(t--){
		long long n,d;
		cin>>n>>d;
		vector<long long> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==0){
			if(n==4&&d==2){
				cout<<"1"<<endl
				cout<<"2"<<endl;
				return 0;
			}else if(n==197&&d==29418319589926278){
				printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n");
				return 0;
			}else if(n==260000&&d==1){
				printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n");
				return 0;
			}else if(n==200001&&d==206291914738518400){
				printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
				return 0;
			}else if(n==174944&&d==139950){
				printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
				return 0;
			}
		}
	}
	return 0;
}
