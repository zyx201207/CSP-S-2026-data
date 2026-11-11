#include <iostream>

using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n;
    cin>>n;
    int m;
    cin>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b[100];
    int c[n];
    for(int i=0;i<n;i++){
    	c[i]=0;
	}
    int d=0;
    for(int aa=0;aa<n;aa++){
        for(int i=0;i<n;i++){
            b[d]=a[d];
            for(int j=0;j<d;j++){
                if(b[d]==b[j]&&d!=j){
                    d=0;
                    for(int k=0;k<d;k++){
                        b[k]=0;
                    }
                }
            }
            d++;
        }
        for(int i=0;i<d;i++){
            c[b[i]]++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<c[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
