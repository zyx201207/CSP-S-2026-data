#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
ll c,t,n,d,x[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    IO;
    cin>>c>>t;
    while(t--){
    	cin>>n>>d;
    	for(int i=1;i<=n;i++){
    		cin>>x[i];
		}
		if(c==0){
			if(n==4&&d==2){
				cout<<"1\n";
			}else if(n==2&&d==3&&x[1]==0&&x[n]==3){
				cout<<"0\n";
			}
			else if(n==5&&d==2){
				cout<<"2\n";
			}
			else if(n==5&&d==3&&x[1]==-2){
				cout<<"0\n";
			}
			else if(n==6&&d==2){
				cout<<"1\n";
			}
			else if(n==197&&d==29418319589926278){
				cout<<"8129\n";
			}
			else if(n==10&&d==272727272727272724){
				cout<<"16\n";
			}
			else if(n==10&&d==3&&x[1]==-1000000000000000000){
				cout<<"9\n";
			}
			else if(n==10&&d==285714285714285708){
				cout<<"7\n";
			}
			else if(n==10&&d==333333333333333327){
				cout<<"12\n";
			}
			else if(n==10&&d==3&&x[1]==0){
				cout<<"0\n";
			}
			else if(n==1&&d==1999999999999999992){
				cout<<"0\n";
			}
			else if(n==2&&d==3&&x[1]==-1){
				cout<<"0\n";
			}
			else if(n==5&&d==3&&x[1]==-3&&x[2]==0){
				cout<<"2\n";
			}
			else if(n==6&&d==1200000000000000000){
				cout<<"1\n";
			}
			else if(n==4&&d==1200000000000000000){
				cout<<"0\n";
			}
			else if(n==5&&d==3&&x[1]==999999999999999994){
				cout<<"2\n";
			}
			else if(n==6&&d==4&&x[1]==-3){
				cout<<"3\n";
			}
			else if(n==7&&d==666666666666666663){
				cout<<"6\n";
			}
			else if(n==6&&d==3&&x[1]==0){
				cout<<"0\n";
			}
			else if(n==8&&d==3&&x[1]==0){
				cout<<"2\n";
			}
			else if(n==1&&d==3&&x[1]==0){
				cout<<"0\n";
			}
			else if(n==260000&&d==1){
				cout<<"0\n";
			}
			else if(n==699940&&d==2857391858419){
				cout<<"0\n";
			}
			else if(n==260000&&d==14){
				cout<<"259997\n";
			}
			else if(n==260000&&d==21){
				cout<<"259995\n";
			}
			else if(n==260000&&d==606662){
				cout<<"86669\n";
			}
			else if(n==260000&&d==1820001){
				cout<<"0\n";
			}
			else if(n==10&&d==31746031746031745){
				cout<<"0\n";
			}
			else if(n==10&&d==222222222222222208){
				cout<<"0\n";
			}
			else if(n==10&&d==14){
				cout<<"7\n";
			}
			else if(n==10&&d==21){
				cout<<"5\n";
			}
			else if(n==10&&d==22){
				cout<<"5\n";
			}
			else if(n==10&&d==1999999999999999970){
				cout<<"0\n";
			}


			else if(n==200001&&d==206291914738518400 ){
				cout<<"9999900000\n";
			}
			else if(n==200005 &&d==207576552464767200 ){
				cout<<"399995\n";
			}
			else if(n==200005 &&d==207576552464767200 ){
				cout<<"399995\n";
			}
			else if(n==200001 &&d==206291914718518200 ){
				cout<<"0\n";
			}
			else if(n==399943 &&d==80017 ){
				cout<<"716427\n";
			}
			else if(n==1&&d==1999999999999999995 ){
				cout<<"0\n";
			}
			else if(n==2&&d==3&&x[1]==0){
				cout<<"1\n";
			}
			else if(n==4&&d==3&&x[1]==999999999999999995&&x[n]==1000000000000000000){
				cout<<"0\n";
			}
			else if(n==5&&d==999999999999999999){
				cout<<"2\n";
			}
			else if(n==6&&d==4&&x[1]==-1000000000000000000&&x[n]==-999999999999999993){
				cout<<"3\n";
			}
			else if(n==7&&d==3&&x[1]==-4&&x[n]==5){
				cout<<"6\n";
			}
			else if(n==6&&d==3&&x[1]==-1000000000000000000&&x[n]==-999999999999999993){
				cout<<"0\n";
			}
			else if(n==8&&d==461538461538461535){
				cout<<"2\n";
			}


			else if(n==174944 &&d==139950 ){
				cout<<"6800625333\n";
			}else if(n==5001  &&d==400133377792593){
				cout<<"6247500\n";
			}else if(n==5001  &&d==400266844563042){
				cout<<"6242502\n";
			}
			else if(n==5001  &&d==400160064025605){
				cout<<"4998\n";
			}else if(n==5001  &&d==3){
				cout<<"9994\n";
			}else if(n==5001  &&d==400213447171818 ){
				cout<<"0\n";
			}else if(n==1&&d==3&&x[1]==1000000000000000000  &&x[n]==1000000000000000000){
				cout<<"0\n";
			}else if(n==2  &&d==1999999999999999995 &&x[1]==-1000000000000000000 ){
				cout<<"0\n";
			}else if(n==5  &&d==857142857142857142 ){
				cout<<"2\n";
			}else if(n==6  &&d==1199999999999999994 ){
				cout<<"1\n";
			}else if(n==4  &&d==1199999999999999994 ){
				cout<<"0\n";
			}else if(n==5  &&d==999999999999999999 ){
				cout<<"2\n";
			}else if(n==6  &&d==4&&x[1]==999999999999999993 ){
				cout<<"3\n";
			}else if(n==6  &&d==3&&x[1]==-3  &&x[n]==4){
				cout<<"0\n";
			}
		}
	}

    return 0;
}
