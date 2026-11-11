#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int n,m;
void solve1(){
	if(m<=(n+1)/2){
	long long k1,k2,k3,k4,k5,k6,k7,k8,k9,k10;
	long long o1,o2,o3,o4,o5,o6,o7,o8,o9,o10;
	o1=o2=o3=o4=o5=o6=o7=o8=o9=o10=0;
		
	for(int a1=1;a1<=n;a1++){
		k2=k3=k4=k5=k6=k7=k8=k9=k10;
		o1=max(o1,a[1]);
		for(int a2=2;a2<=n;a2++){
			k3=k4=k5=k6=k7=k8=k9=k10=k2&=a[2];
			o2=max(o2,k2&=a[2]);
			for(int a3=3;a3<=n;a3++){
				k4=k5=k6=k7=k8=k9=k10=k3&=a[3];
				o3=max(o3,k3&=a[3]);
				for(int a4=4;a4<=n;a4++){
					k5=k6=k7=k8=k9=k10=k4&=a[4];
					o4=max(o4,k4&=a[4]);
					for(int a5=5;a5<=n;a5++){
						k6=k7=k8=k9=k10=k5&=a[5];
						o5=max(o5,k5&=a[5]);
						for(int a6=6;a6<=n;a6++){
							k7=k8=k9=k10=k6&=a[6];
							o6=max(o6,k6&=a[6]);
							for(int a7=7;a7<=n;a7++){
								k8=k9=k10=k7&=a[7];
								o7=max(o7,k7&=a[7]);
								for(int a8=8;a8<=n;a8++){
									k9=k10=k8&=a[8];
									o8=max(o8,k8&=a[8]);
									for(int a9=9;a9<=n;a9++){
										k10=k9&=a[9];
										o9=max(o9,k9&=a[9]);
										for(int a10=10;a10<=n;a10++){
											o10=max(o10,k10&=a[10]);
			
		}
			
		}
			
		}
			
		}
			
		}
			
		}
		}
		}
		}
	}
	
		if(m==3)cout<<o3;
		else if(m==4)cout<<o4;
		else if(m==5)cout<<o5;
		else if(m==6)cout<<o6;
		else if(m==7)cout<<o7;
		else if(m==8)cout<<o8;
		else if(m==9)cout<<o9;
		else if(m==10)cout<<o10;
	}
	else{
	long long o=a[1];
	for(int i=2;i<=n;i++){
		o&=a[i];
	}
	long long k1,k2,k3,k4,k5,k6,k7,k8,k9,k10;
	long long o1,o2,o3,o4,o5,o6,o7,o8,o9,o10;
	o1=o2=o3=o4=o5=o6=o7=o8=o9=o10=0;
		
	for(int a1=1;a1<=n;a1++){
		k2=k3=k4=k5=k6=k7=k8=k9=k10;
		long long t=o;
		t&=a[1];
		o1=max(o1,t);
		for(int a2=2;a2<=n;a2++){
			k3=k4=k5=k6=k7=k8=k9=k10=k2&=a[2];
			long long t=o;
			t&=k2&=a[2];
			o2=max(o2,t);
			for(int a3=3;a3<=n;a3++){
				k4=k5=k6=k7=k8=k9=k10=k3&=a[3];
				long long t=o;
				t&=k3&=a[3];
				o3=max(o3,k3&=a[3]);
				for(int a4=4;a4<=n;a4++){
					k5=k6=k7=k8=k9=k10=k4&=a[4];
					long long t=o;
					t&=k4&=a[4];				
					o4=max(o4,k4&=a[4]);
					for(int a5=5;a5<=n;a5++){
						k6=k7=k8=k9=k10=k5&=a[5];
						long long t=o;
						t&=k5&=a[5];
						o5=max(o5,k5&=a[5]);
						for(int a6=6;a6<=n;a6++){
							k7=k8=k9=k10=k6&=a[6];
							long long t=o;
							t&=k6&=a[6];
							o6=max(o6,k6&=a[6]);
							for(int a7=7;a7<=n;a7++){
								k8=k9=k10=k7&=a[7];
								long long t=o;
								t&=k7&=a[7];
								o7=max(o7,k7&=a[7]);
								for(int a8=8;a8<=n;a8++){
									k9=k10=k8&=a[8];
									long long t=o;
									t&=k8&=a[8];								
									o8=max(o8,k8&=a[8]);
									for(int a9=9;a9<=n;a9++){
										k10=k9&=a[9];
										long long t=o;
										t&=k9&=a[9];	
										o9=max(o9,k9&=a[9]);
										for(int a10=10;a10<=n;a10++){
											long long t=o;
											t&=k10&=a[10];	
											o10=max(o10,k10&=a[10]);
			
		}
			
		}
			
		}
			
		}
			
		}
			
		}
		}
		}
		}
	}		

		if(m==3){
			o&=o3;
			cout<<o;
		}
		else if(m==4){
			o&=o4;
			cout<<o;
		}
		else if(m==5){
			o&=o5;
			cout<<o;
		}
		else if(m==6){
			o&=o6;
			cout<<o;
		}
		else if(m==7){
			o&=o7;
			cout<<o;	
		}
		else if(m==8){
			o&=o8;
			cout<<o;
		}
		else if(m==9){
			o&=o9;
			cout<<o;
		}
		else if(m==10){
			o&=o10;
			cout<<o;
		}
	}
	return ;
}
void solve2(){
	long long o=0;
	for(int i=1;i<=n;i++){
		o=max(o,a[i]);
	}
	cout<<o;
	return ;
}
void solve3(){
	long long o=a[1];
	for(int i=2;i<=n;i++){
		o&=a[i];
	}
	cout<<o;
	return ;
}
void solve4(){
	long long o=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			long long k=a[i];
			k&=a[j];
			o=max(k,o);
	//		cout<<k<<endl;
		}
	}
	cout<<o;
	return ;
}
void solve5(){
	long long o=a[1];
	for(int i=2;i<=n;i++){
		o&=a[i];
	}
	long long t=0;
	for(int i=1;i<=n;i++){
		t=max(t,o&a[i]);
	}
	cout<<t;
	return ;	
}
int main(){
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		cout<<a[i]<<endl;
	}
	
	if(m==1)solve2();
	else if(m==n)solve3();
	else if(m==2)solve4();
	else if(m==n-1)solve5();
	else if(n<=20)solve1();
}
