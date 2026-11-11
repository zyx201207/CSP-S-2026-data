#include <bits/stdc++.h>

using namespace std;

int a[500010],m[300010];

int main()
{
    int m,n;
    cin>>n>>m;
    stack<int> st;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=0;k<=i;k++){
                st.push(a[i]);
                if(a[i]==a[k]){
                    while((k-i)--){
                        st.pop();
                    }
                    st.push(a[i]);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<st[i]<<endl;
    }

    return 0;

}
