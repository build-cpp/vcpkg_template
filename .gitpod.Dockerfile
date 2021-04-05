FROM gitpod/workspace-full

USER gitpod
RUN git clone https://github.com/mrexodia/vcpkg_template /tmp/vcpkg_template \
 && cmake -B/tmp/vcpkg_template/build /tmp/vcpkg_template \
 && cmake --build /tmp/build \
 && rm -rf /tmp/vcpkg_template