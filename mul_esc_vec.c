void mul_esc_vec(int *a, int b, int *c, int N){
    for (int i = 0; i<N;i++)
    {
        c[i] = b*a[i];
    }    
}