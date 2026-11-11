#include<bits/stdc++.h>
#define int long long
using namespace std;
struct block{
	int l;
	char c;
}lef[1000005],rig[1000005],a[1000005];
int n,num1,sum,sum2,rigl,lefl,suml,sumr,lsuml,lsumr,sam;
char num2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num1>>num2,a[i]={num1,num2};
		sum+=num1;
	}
	int i=1;
	for(i;sum2<=sum/2;i++){
		sum2+=a[i].l;
		lef[i].c=a[i].c,lef[i].l=a[i].l;
	}
	int t=i-1;
	if(sum%2==1)lef[i-1].l--,sum2--;
	lef[i-1].l=lef[i-1].l-sum2+sum/2;
	if(sum2!=sum/2){
		rig[i-t].l=sum2-sum/2,rig[i-t].c=lef[i-1].c;
		t--;
	}
	for(i;i<=n;i++){
		rig[i-t].l=a[i].l,rig[i-t].c=a[i].c;
	}
	for(int j=1;lef[j].l;j++)lefl++;
	if(lef[lefl+1].l==0)lef[lefl+1].c='*';
	for(int j=1;rig[j].l;j++)rigl++;
	for(int j=1;j<=lefl/2;j++){
		swap(lef[j],lef[lefl-j+1]);
	}
	for(int i=1,j=1;i-1<=lefl&&j-1<=rigl;){
		if((suml<=sumr||j>rigl)&&i<=lefl){
			lsuml=suml;
			suml+=lef[i].l;
			if(lef[i].c==rig[j-1].c){
				if(suml>=sumr)sam+=sumr-lsuml;
				else sam+=suml-lsuml;
			}
			i++;
		}
		else{
			lsumr=sumr;
			sumr+=rig[j].l;
			if(rig[j].c==lef[i-1].c){
				if(sumr>=suml)sam+=suml-lsumr;
				else sam+=sumr-lsumr;
			}
			j++;
		}
	}
	cout<<sum/2-sam;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5
1 a
2 b
3 c
2 b
1 a
*/
/*
3
2 a
2 b
1 c
*/ 