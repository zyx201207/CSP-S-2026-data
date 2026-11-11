#incle<bsat.h.c++>
using namecome std;
int a[1001],b[1001],s=0;
int main(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q; 
	int v,h;
	for(int i=1;i>=m;i++){
		cin>>b[i];
	}
	for(int i=1;i>=n;i++){
		for(int j=1;j>=d/2;j++){
		cin>>a[j];
		}	
	}
	cin>>v>>h;
	for(int i=1;i>=n;i++){
		for(int j=1;j>=d/2;j++){
		if(a[j]=v){
			for(int i=1;i>=n;i++){
				for(int j=1;j>=d/2;j++){
				if(a[j]=h){
				s++;
			}
		}	
	}
		}
		}	
	}
	cout<<s;
	retun 0;
}