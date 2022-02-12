#!/bin/bash

# Direct solver to generate initial data
./fsitimedependent -input "./input/turek_FSI3.neu" -n_timesteps 120 -autosave_time_interval 120 -nlevel 1 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "preonly" -max_outer_solver_iter 1 -nrefinement 4

###########################################

# Direct solver for time info
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_3_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -nlevel 1 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "preonly" -max_outer_solver_iter 1 -nrefinement 3 -std_output fsi3_3_preonly.txt > fsi3_3_preonly.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -nlevel 1 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "preonly" -max_outer_solver_iter 1 -nrefinement 4 -std_output fsi3_4_preonly.txt > fsi3_4_preonly.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_5_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -nlevel 1 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "preonly" -max_outer_solver_iter 1 -nrefinement 5 -std_output fsi3_5_preonly.txt > fsi3_5_preonly.txt

# Direct solver for convergence and MUMPS info
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_3_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -nlevel 1 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 1 -ksp_monitor_true_residual -ksp_view -mat_mumps_icntl_11 1 -nrefinement 3 -std_output fsi3_3_gmres.txt > fsi3_3_gmres.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -nlevel 1 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 1 -ksp_monitor_true_residual -ksp_view -mat_mumps_icntl_11 1 -nrefinement 4 -std_output fsi3_4_gmres.txt > fsi3_4_gmres.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_5_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -nlevel 1 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 1 -ksp_monitor_true_residual -ksp_view -mat_mumps_icntl_11 1 -nrefinement 5 -std_output fsi3_5_gmres.txt > fsi3_5_gmres.txt


############################################

# Multigrid solver for time info
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_3_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -nrefinement 3  -nlevel 3  -std_output fsi3_3_gmres_time.txt > fsi3_3_gmres_time.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -nrefinement 4  -nlevel 4  -std_output fsi3_4_gmres_time.txt > fsi3_4_gmres_time.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_5_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -nrefinement 5  -nlevel 5  -std_output fsi3_5_gmres_time.txt > fsi3_5_gmres_time.txt

# Multigrid solver for convergence and memory info
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_3_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -ksp_monitor_true_residual -mem_infos 1 -nrefinement 3  -nlevel 3  -std_output fsi3_3_gmres.txt > fsi3_3_gmres.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -ksp_monitor_true_residual -mem_infos 1 -nrefinement 4  -nlevel 4  -std_output fsi3_4_gmres.txt > fsi3_4_gmres.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_5_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -ksp_monitor_true_residual -mem_infos 1 -nrefinement 5  -nlevel 5  -std_output fsi3_5_gmres.txt > fsi3_5_gmres.txt


########### npre-npost ######################

./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -nrefinement 4  -nlevel 4  -npre 2 -npost 2 -std_output fsi3_22_time.txt > fsi3_22_time.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -nrefinement 4  -nlevel 4  -npre 4 -npost 4 -std_output fsi3_44_time.txt > fsi3_44_time.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -nrefinement 4  -nlevel 4  -npre 8 -npost 8 -std_output fsi3_88_time.txt > fsi3_88_time.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -nrefinement 4  -nlevel 4  -npre 2 -npost 4 -std_output fsi3_24_time.txt > fsi3_24_time.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -nrefinement 4  -nlevel 4  -npre 4 -npost 2 -std_output fsi3_42_time.txt > fsi3_42_time.txt


./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -ksp_monitor_true_residual -mem_infos 1 -nrefinement 4  -nlevel 4  -npre 2 -npost 2 -std_output fsi3_22_meminfo.txt > fsi3_22_meminfo.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -ksp_monitor_true_residual -mem_infos 1 -nrefinement 4  -nlevel 4  -npre 4 -npost 4 -std_output fsi3_44_meminfo.txt > fsi3_44_meminfo.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -ksp_monitor_true_residual -mem_infos 1 -nrefinement 4  -nlevel 4  -npre 8 -npost 8 -std_output fsi3_88_meminfo.txt > fsi3_88_meminfo.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -ksp_monitor_true_residual -mem_infos 1 -nrefinement 4  -nlevel 4  -npre 2 -npost 4 -std_output fsi3_24_meminfo.txt > fsi3_24_meminfo.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -ksp_monitor_true_residual -mem_infos 1 -nrefinement 4  -nlevel 4  -npre 4 -npost 2 -std_output fsi3_42_meminfo.txt > fsi3_42_meminfo.txt

########## vanka blok size #####################

./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -nrefinement 4  -nlevel 4  -asm_block 1 -std_output fsi3_1_time.txt > fsi3_1_time.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -nrefinement 4  -nlevel 4  -asm_block 2 -std_output fsi3_2_time.txt > fsi3_2_time.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -nrefinement 4  -nlevel 4  -asm_block 3 -std_output fsi3_3_time.txt > fsi3_3_time.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -nrefinement 4  -nlevel 4  -asm_block 4 -std_output fsi3_4_time.txt > fsi3_4_time.txt

./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -ksp_monitor_true_residual -mem_infos 1 -nrefinement 4  -nlevel 4  -asm_block 1 -std_output fsi3_1_meminfo.txt > fsi3_1_meminfo.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -ksp_monitor_true_residual -mem_infos 1 -nrefinement 4  -nlevel 4  -asm_block 2 -std_output fsi3_2_meminfo.txt > fsi3_2_meminfo.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -ksp_monitor_true_residual -mem_infos 1 -nrefinement 4  -nlevel 4  -asm_block 3 -std_output fsi3_3_meminfo.txt > fsi3_3_meminfo.txt
./fsitimedependent -input "./input/turek_FSI3.neu" -restart_file_name http://www.math.ttu.edu/~eaulisa/Benchmarks/runs/save/FSI3/turek_FSI3_4_time6.420000 -n_timesteps 10 -autosave_time_interval 40 -rhof 1000 -muf 1 -rhos 1000 -E 6000000 -ni 0.5 -ic_bdc "../../../../lib64/libfsi3_td_2d_turek_hron_benchmark_bdc.so" -outer_ksp_solver "gmres" -max_outer_solver_iter 60 -ksp_monitor_true_residual -mem_infos 1 -nrefinement 4  -nlevel 4  -asm_block 4 -std_output fsi3_4_meminfo.txt > fsi3_4_meminfo.txt

