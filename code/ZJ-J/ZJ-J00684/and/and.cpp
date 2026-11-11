#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[35],c2[35],mx;
int pos[30][200005];
//long long 
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	c2[0]=1;
	c2[1]=2;
    c2[2]=4;
    c2[3]=8;
    c2[4]=16;
    c2[5]=32;
    c2[6]=64;
    c2[7]=128;
    c2[8]=256;
    c2[9]=512;
    c2[10]=1024;
    c2[11]=2048;
    c2[12]=4096;
    c2[13]=8192;
    c2[14]=16384;
    c2[15]=32768;
    c2[16]=65536;
    c2[17]=131072;
    c2[18]=262144;
    c2[19]=524288;
    c2[20]=1048576;
    c2[21]=2097152;
    c2[22]=4194304;
    c2[23]=8388608;
    c2[24]=16777216;
    c2[25]=33554432;
    c2[26]=67108864;
    c2[27]=134217728;
    c2[28]=268435456;
    c2[29]=536870912;
    c2[30]=1073741824;
    
    for(int i = 1;i <=30;i++){
    	if(mx<c2[i]){
    		mx=i-1;
		}
	}
	/*while(m--){
		c*=2;
		i++;
		cout<<"    c2["<<i<<"]="<<c<<";\n";
	}
    */
    int cnt=0,last=0;
	for(int i = mx;i >= 0;i--){
		cnt=0;
		for(int j = 1;j <= n;j++){
			int t=c2[i]&a[j];
		//	cout<<t<<" ";
			if((c2[i]&a[j])!=0){
				b[i]++;
				pos[i][++cnt]=j;
				/*if(c2[i]==4){
					cout<<"\n!!!";
					cout<<pos[i][cnt]<<"\n";
				}*/
			}
		}//cout<<"\n";
		//if(c2[i]==4)cout<<"!!!"<<pos[i][1]<<"\n";
		if(b[i]>m){
			
			last=i;
			break;
		}
		if(b[i]==m){
			//cout<<b[i]<<"\n";
			long long tmp=a[pos[i][1]];
			for(int j = 2;j <= m;j++){
				tmp=a[pos[i][j]]&tmp;
				//cout<<tmp<<"\n";
				
			}
			cout<<tmp;
			return 0;
		}
		
	}
//	cout<<last<<"\n";
	//*/
	int cntlt=cnt;
	for(int i = last-1;i >= 0;i--){
		cnt=0;
		for(int j = 1;j <= cntlt;j++){
			int t=c2[i]&a[pos[last][j]];
		//	cout<<t<<" ";
			if((c2[i]&a[pos[last][j]])!=0){
				b[i]++;
				pos[i][++cnt]=pos[last][j];
				
			}
		}//cout<<"   "<<cnt<<"\n";
	//	cout<<" "<<b[i]<<"\n";
		if(b[i]>m){
			last=i;
			cntlt=cnt;
			continue;
		}
		if(b[i]==m){
			
			long long tmp=a[pos[i][1]];
			for(int j = 2;j <= m;j++){
				tmp=a[pos[i][j]]&tmp;
				//cout<<tmp<<"\n";
			}
			cout<<tmp;
			return 0;
		}
	
		
	}
	long long tmp=a[pos[last][1]];
	for(int j = 2;j <= m;j++){
		tmp=a[pos[last][j]]&tmp;
		//cout<<tmp<<"\n";
	}
	cout<<tmp;
	//*/
	return 0;
}