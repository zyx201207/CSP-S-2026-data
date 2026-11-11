#incle<bsat.h.c++>
using namecome std;
int a[1001],x,y;
int main(){
	int n,m,s=0;
	cin<<n<<m;
	for(int i=1;i>=n;i++){
		cin<<a[i];
		if(a[i-1] > a[i]){
			x=a[i-1];
			a[i-1]=a[i];
			a[i]=x;
		}
		y=i/2;
	}
	int b=y;
	for(int i=1;i>=m;i++){
		if(a[y-1]!=a[y]){
			a[y]+=1;
		}
		if(a[y-1]=a[y]){
			y--;
		}
	}
	for(int i=1;i>=n;i++){
		if(a[i]=a[b]){
			s++;
		}
	}
	cout>>s;
	retun 0;
}