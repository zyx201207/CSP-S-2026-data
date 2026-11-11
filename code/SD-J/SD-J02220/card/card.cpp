#include<iostream> 
using namespace std;
int p,g,fg;
int* z;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>p>>g;
	int gy[p],gn[p]={},jj[p]={},mxn=-100;
	for(int i=0;i<p;i++){
	cin>>gy[i];
	}
	for(int i=0;i<g;i++){
		z=gn+i;
    	for(int i1=i;i1<g;i1++){
    		fg=-1;
    		for(int i2=0;i2<i1-i-1;i2++){
    			if(gn[i2]==gy[i1]){
    				fg=i1;
    				break;
				}
			}
			if(fg!=-1){
				z-=fg
			}
    		*z=gy[i1];
		}
		for(int i1=0;gn+i+i1<z;i1++){
    		jj[gn[i+i1]]++;
    		mxn=max(gn[i+i1],mxn);
		}
	}
	for(int i=1;i<=mxn;i++){
    	cout<<jj[i]<<' ';
	}
	cout<<endl;
	return 0;
}
